-- DropForeignKey
ALTER TABLE "block" DROP CONSTRAINT "block_blockedChannelUserId_fkey";

-- DropForeignKey
ALTER TABLE "block" DROP CONSTRAINT "block_blockerChannelUserId_fkey";

-- AddForeignKey
ALTER TABLE "block" ADD CONSTRAINT "block_blockerChannelUserId_fkey" FOREIGN KEY ("blockerChannelUserId") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "block" ADD CONSTRAINT "block_blockedChannelUserId_fkey" FOREIGN KEY ("blockedChannelUserId") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
